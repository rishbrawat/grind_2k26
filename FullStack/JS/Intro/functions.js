/*
   functions are the building block of the program, it allows us to wrap code under a single name.
   functions make code reusable and increase readability.
 */

// create the  function 
function showMessage(){
   console.log('holow from the function!');
}
// now call it to execute it in the main flow of the program
showMessage();


// we can take parameters(placeholder values) if we want to work on some specific data
let a = 10, b = 10;

function addTwoNums(num1, num2) {
   return num1 + num2;
}
console.log(addTwoNums(a, b));


// local variables inside the function belongs only to that function, using it outside the body will give undefined error. if we have a outer variable and inner variable named equally then the inner variable will be used.
function newYearMessage(){
   let nym = 'happy new year';
   console.log(nym);
}
newYearMessage();
// nym = 'this is not defined'; its outside of the function body


// global vars = variable declared outside of any function.

// if a function is called, but an argument is not provided then the corresponding value becomes undefined, and numerical return functions values becomes NaN

// to fix this we can use default values

function showMessage(from, text = "no text given") {
   console.log( from + ": " + text );
}
showMessage("rishab","js sucks");


// this is also possible: func showmsg(from, text=somefunc()){....}
// a function without return, returns undefined.
// a function in js is a value so we can copy a function to a variable directly.



// function expression: allows to create a function in the middle of an expression
let sum =  function () {
   return a+b; 
}; // healthy practice to put it at the end of the the }
console.log(sum());

/* callback functions
   a function passed as an argument to another function then executed later.

   in basic terms it means: once your task is finished, run this function for me.

   callbacks allows to avoid blocking execution while still defining what should happen when the data is available.
*/

function greetUser(uname, callback) {
   console.log("hello "+uname);
   callback();
}
function goodbye() {
   console.log("goodbye!");
}
greetUser('rishbh', goodbye);


/*
Arrow functions are a shorter syntax for writing functions in JavaScript.
They are commonly used for cleaner, more readable code, especially with
callbacks and functional programming patterns.
*/

/*
BASIC SYNTAX:
(parameters) => expression
If there is only ONE expression, it is returned implicitly.
*/
const add = (a, b) => a + b;

/*
EXPLICIT RETURN:
If you use curly braces {}, you MUST use the `return` keyword.
*/
const multiply = (a, b) => {
  return a * b;
};

/*
SINGLE PARAMETER:
Parentheses can be omitted if there is only one parameter.
*/
const square = x => x * x;

/*
NO PARAMETERS:
Parentheses are required if there are no parameters.
*/
const greet = () => "Hello, world!";

/*
MULTI-LINE FUNCTION BODY:
Useful for more complex logic.
*/
const calculateArea = (width, height) => {
  const area = width * height;
  return area;
};
