 const state = {
            postfixExpression: [],
            steps: [],
            currentStepIndex: -1,
            finalResult:" "
        };

        const $ = (id) => document.getElementById(id);
        const infixInput = $('infixInput');
        const convertBtn = $('convertBtn');
        const postfixDisplay = $('postfixDisplay');
        const stackDisplay = $('stack-display');
        const errorMsg = $('errorMsg');
        const resultSection = $('resultSection');
        const animationSection = $('animationSection');
        const prevStepBtn = $('prevStepBtn');
        const nextStepBtn = $('nextStepBtn');
        const restartBtn = $('restartBtn');
        const animationMessage = $('animationMessage');
        const tokenProcessed = $('tokenProcessed');
        const actionType = $('actionType');
        const currentResult = $('currentResult');

        class Stack {
            constructor() {
                this.items = [];
            }
            push(element) {
                this.items.push(element);
            }
            pop() {
                if (this.isEmpty()) return null;
                return this.items.pop();
            }
            peek() {
                if (this.isEmpty()) return null;
                return this.items[this.items.length - 1];
            }
            isEmpty() {
                return this.items.length === 0;
            }
            toArray() {
                return [...this.items];
            }
        }

        function precedence(operator) {
            if (operator === '+' || operator === '-') return 1;
            if (operator === '*' || operator === '/') return 2;
            if (operator === '^') return 3;
            return 0;
        }

        function isRightAssociative(operator) {
            return operator === '^';
        }

        function convertInfixToPostfix(infix) {
            const output = [];
            const opStack = new Stack();
            
            const inputWithoutSpaces = infix.replace(/\s+/g, '');
            
            const allowedTokenRegex = /(\d+|\+|\-|\*|\/|\^|\(|\))/g;
            const tokens = inputWithoutSpaces.match(allowedTokenRegex);
            
            const reconstructedString = tokens ? tokens.join('') : '';
            if (inputWithoutSpaces !== reconstructedString) {
                errorMsg.textContent = "Invalid operator or unsupported character detected. Only single digits and +, -, *, /, ^, (, ) are supported.";
                errorMsg.classList.remove('hidden');
                return null;
            }

            if (!tokens || tokens.length === 0) {
                 errorMsg.textContent = "Please enter a valid expression.";
                 errorMsg.classList.remove('hidden');
                 return null;
            }

            errorMsg.classList.add('hidden');

            for (const token of tokens) {
                if (!isNaN(parseInt(token))) {
                    output.push(token);
                } else if (token === '(') {
                    opStack.push(token);
                } else if (token === ')') {
                    while (opStack.peek() !== '(' && !opStack.isEmpty()) {
                        output.push(opStack.pop());
                    }
                    if (opStack.isEmpty() || opStack.pop() !== '(') {
                        errorMsg.textContent = "Mismatched parentheses.";
                        errorMsg.classList.remove('hidden');
                        return null;
                    }
                } else {
                    const currentOpPrecedence = precedence(token);
                    let stackTopPrecedence = precedence(opStack.peek());
                    
                    while (!opStack.isEmpty() && opStack.peek() !== '(') {
                        const topOp = opStack.peek();
                        stackTopPrecedence = precedence(topOp);

                        if (currentOpPrecedence < stackTopPrecedence || 
                            (currentOpPrecedence === stackTopPrecedence && !isRightAssociative(token))) {
                            output.push(opStack.pop());
                        } else {
                            break;
                        }
                    }
                    opStack.push(token);
                }
            }

            while (!opStack.isEmpty()) {
                if (opStack.peek() === '(') {
                    errorMsg.textContent = "Misssed Closed bracket.";
                    errorMsg.classList.remove('hidden');
                    return null;
                }
                output.push(opStack.pop());
            }

            if (output.length < 3 && tokens.filter(t => isNaN(parseInt(t)) && t !== '(' && t !== ')').length === 0) {
                errorMsg.textContent = "Invalid expression structure (e.g., only numbers or insufficient operators).";
                errorMsg.classList.remove('hidden');
                return null;
            }

            return output;
        }

        function generateEvaluationSteps(postfixTokens) {
            const stack = new Stack();
            const steps = [];

            for (let i = 0; i < postfixTokens.length; i++) {
                const token = postfixTokens[i];

                if (!isNaN(parseInt(token))) {
                    const operandValue = parseInt(token);
                    stack.push(operandValue);
                    steps.push({
                        token: token,
                        tokenIndex: i,
                        action: 'PUSH',
                        description: `Encountered operand '${token}'. Pushing value ${operandValue} onto the stack.`,
                        newStack: stack.toArray()
                    });
                } else if (['+', '-', '*', '/', '^'].includes(token)) {
                    if (stack.items.length < 2) {
                        throw new Error("Evaluation error: Not enough operands on the stack for the operator.");
                    }
                    const op2 = stack.pop();
                    const op1 = stack.pop();
                    let result;
                    let description;

                    switch (token) {
                        case '+': result = op1 + op2; description = `Popping ${op2} and ${op1}. Calculating ${op1} + ${op2} = ${result} &  Pushing result.`; break;
                        case '-': result = op1 - op2; description = `Popping ${op2} and ${op1}. Calculating ${op1} - ${op2} = ${result} &  Pushing result.`; break;
                        case '*': result = op1 * op2; description = `Popping ${op2} and ${op1}. Calculating ${op1} * ${op2} = ${result} &  Pushing result.`; break;
                        case '/': 
                            if (op2 === 0) throw new Error("Division by zero detected.");
                            result = Math.floor(op1 / op2);
                            description = `Popping ${op2} and ${op1}. Calculating ${op1} / ${op2} = ${result} &  Pushing result.`;
                            break;
                        case '^':
                            result = Math.pow(op1, op2);
                            description = `Popping ${op2} and ${op1}. Calculating ${op1} ^ ${op2} = ${result} & Pushing result.`;
                            break;
                    }
                    
                    if (result > 999999) {
                        result = result.toExponential(2);
                    }
                    
                    stack.push(result);
                    steps.push({
                        token: token,
                        tokenIndex: i,
                        action: 'CALCULATE',
                        description: `Encountered operator '${token}'. ${description}`,
                        newStack: stack.toArray()
                    });

                } else {
                    throw new Error(`Internal Error: Unknown token encountered: ${token}`);
                }
            }

            if (stack.items.length === 1) {
                const finalResult = stack.pop();
                steps.push({
                    token: '',
                    tokenIndex: postfixTokens.length,
                    action: 'DONE',
                    description: `Evaluation complete! The final result is ${finalResult}.`,
                    newStack: [],
                    finalResult: finalResult
                });
                state.finalResult = finalResult;
            } else {
                throw new Error("Evaluation error: Stack contains too many items after processing all tokens. Check input syntax.");
            }

            return steps;
        }

        function renderPostfixTokens() {
            postfixDisplay.innerHTML = state.postfixExpression.map((token, index) =>
                `<span id="token-${index}" class="px-3 py-1 bg-gray-200 rounded-md font-mono text-xl shadow-sm transition duration-150">${token}</span>`
            ).join('');
        }

        function renderStack(stackArray) {
            stackDisplay.innerHTML = stackArray.map((value, index) => {
                const isTop = index === stackArray.length - 1;
                
                const topIndicator = isTop ? 
                    `<span class="absolute right-0 translate-x-full top-1/2 -translate-y-1/2 text-sm font-bold text-red-700 bg-red-100 px-1.5 py-0.5 rounded-r-lg shadow-md border-y border-r border-red-300">TOP</span>` : 
                    '';

                return `<div class="stack-item p-3 w-full bg-indigo-200 text-indigo-900 font-mono text-xl text-center rounded-lg relative ${isTop ? 'highlight' : ''}">
                            ${value}
                            ${topIndicator}
                        </div>`;
            }).join('');
            
            stackDisplay.scrollTop = stackDisplay.scrollHeight;
        }

        function updateUI() {
            const step = state.steps[state.currentStepIndex];
            
            document.querySelectorAll('#postfixDisplay span').forEach(el => el.classList.remove('token-current'));
            
            if (step) {
                const currentTokenEl = $(`token-${step.tokenIndex}`);
                if (currentTokenEl) {
                    currentTokenEl.classList.add('token-current');
                }

                animationMessage.textContent = step.description;
                tokenProcessed.textContent = step.token || '';
                actionType.textContent = step.action;
                
                renderStack(step.newStack);

                nextStepBtn.disabled = (state.currentStepIndex >= state.steps.length - 1);
                prevStepBtn.disabled = (state.currentStepIndex <= 0);

                if (step.action === 'DONE') {
                    currentResult.innerHTML = `Final Result: <span class="font-mono text-3xl">${step.finalResult}</span>`;
                    animationMessage.classList.add('bg-green-100', 'text-green-800');
                    animationMessage.classList.remove('bg-indigo-100', 'text-indigo-800');
                } else {
                    currentResult.innerHTML = `Final Result: <span class="font-mono text-3xl">--</span>`;
                    animationMessage.classList.remove('bg-green-100', 'text-green-800');
                    animationMessage.classList.add('bg-indigo-100', 'text-indigo-800');
                }
            }
        }

        convertBtn.addEventListener('click', () => {
            const infix = infixInput.value.trim();
            if(infix==""){
                errorMsg.textContent="Input field is empty"
                errorMsg.classList.remove('hidden');
                return;
            }
            try {
                const postfix = convertInfixToPostfix(infix);
                if (postfix) {
                    state.postfixExpression = postfix;
                    state.steps = generateEvaluationSteps(postfix);
                    state.currentStepIndex = -1;

                    renderPostfixTokens();
                    resultSection.classList.remove('hidden');
                    animationSection.classList.remove('hidden');
                    
                    restartEvaluation();
                } else {
                    resultSection.classList.add('hidden');
                    animationSection.classList.add('hidden');
                }
            } catch (e) {
                errorMsg.textContent = e.message;
                errorMsg.classList.remove('hidden');
                resultSection.classList.add('hidden');
                animationSection.classList.add('hidden');
            }
        });

        nextStepBtn.addEventListener('click', () => {
            if (state.currentStepIndex < state.steps.length - 1) {
                state.currentStepIndex++;
                updateUI();
            }
        });
        
        prevStepBtn.addEventListener('click', () => {
            if (state.currentStepIndex > 0) {
                state.currentStepIndex--;
                updateUI();
            } else if (state.currentStepIndex === 0) {
                restartEvaluation();
            }
        });

        restartBtn.addEventListener('click', restartEvaluation);

        function restartEvaluation() {
            state.currentStepIndex = -1;
            nextStepBtn.disabled = false;
            prevStepBtn.disabled = true;
            
            animationMessage.textContent = `Ready to evaluate the Postfix expression. There are ${state.steps.length} steps. Click 'Next Step' to start.`;
            tokenProcessed.textContent = '';
            actionType.textContent = 'START';
            currentResult.innerHTML = `Final Result: <span class="font-mono text-3xl"></span>`;
            renderStack([]);
            
            document.querySelectorAll('#postfixDisplay span').forEach(el => el.classList.remove('token-current'));
            
            if (state.postfixExpression.length > 0) {
                 const firstTokenEl = $(`token-0`);
                 if (firstTokenEl) firstTokenEl.classList.add('token-current');
            }
             animationMessage.classList.remove('bg-green-100', 'text-green-800');
             animationMessage.classList.add('bg-indigo-100', 'text-indigo-800');
        }

        window.onload = () => {
            convertBtn.click();
            restartEvaluation();
        };