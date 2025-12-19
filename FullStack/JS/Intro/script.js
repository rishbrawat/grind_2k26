// okay this thing enables the engine to use modern javascript and discard old uncompatible syntax stuff, have to put this at top most and if we use classes or modules this is not required as they do it automatically
'use strict';

//  use strict prevents 'accidental variable creation without using type' 

/* 
   javascript is used to make web pages alive, the programs in this languages is called scripts, they can also be written in html and they run automatically in the browser once the page loads.

   LiveScript -> JavaScript

   javascript becomes its fully independent language through its specifications called ecmascript.


   javascript can run on anything as long as it has javascript engine that is called javascript virutal machine.
   v8 - chrome
   spidermonkey - firefox
   chakra - ie


   javascript scripts -> javascript engine -> machine code
*/

// [1, 2].forEach(alert);


/* 
   a variable is a named storage for the data. a variable should only be decalred once, repeated declaration will result in an error.

   reserved names such as class, interface, module, function, return shuold not be used.
*/


// let variables's value can change throughout the program
let uname = 'John';
console.log(uname);

// we can also declare multiple variables into a single line, but for better readability single line per var is preferred.
let age = 25, salary = 5000;


// constants: unchanging variables, they can not be reassigned
const jsVersion = 'ecmascript6';

// jsVersion = 'ecmascript7'; will throw an error.

//________________________________________________________



/*
   data types
   _______________

   data type defines the type of value that will be stored in the variable, in js there are 8 basic data types. 
   since js determines the type dynamically, its not a static typed language, we don't explicitly need to say 
   const int age = 20, we can simply say let age = 20, and compiler will know its number type.
*/

// number types: supports math ops like DMASM and so on, there are special numeric values such as Infinity, -Infinity, NaN

console.log(Infinity);

// NaN represents a computational error, result of a undefined or incorrect mathematical operation 

const message = "hello world";
console.log(message/4); // output -> NaN, any further operation on NaN results in NaN

// in js we can divide by 0
console.log(Infinity/0); // will result in Infinity

// a bigInt is used for storing value large numerical values > 2^53-1, we need to append 'n' at the end to say its bigInt type

const bigInt = 1234567891098765432012345678910n;
console.log(bigInt);


// string: a textual value, the string must be enclosed with double quotes or single quotes, these are simple quotes
let firstName = 'Java';
// or
let lastName = "Script";


// `value`: backtick quotes are special types, they extend functionality, they allow us to embed variables and expressions in a string and they are wrapped inside ${ }.

const fullName = `the full name is: ${firstName+lastName}`
console.log(fullName);

// also we can do this, the expression inside the ${} is evaluated and added to the string
console.log(`the result of 5+3 = ${5+3}`);

// boolean type: stores only true and false values

let isValid = true;
let isNotValid = false;

// null type doesn't mean the data doesn't belong to any existing kind, represents nothing, empty or value unknown
let voidval = null;

// undefined: means value is not defined
let pii;
console.log(pii);

// other data types like objects and symbol will be covered later.

// typeof operator: returns the type of the data
console.log(typeof bigInt);


// prompt, alert and confirm: these pauses the further script execution

// alert: it shows a message in a modal window and waits for the user to press ok.
// the word 'modal' means the user can not interact with the page as long as that 'modal window is open'.
// alert('hello js');

// prompt: takes two arguments: a modal window that takes input from the user and the buttons ok/cancel, the input can be canceled using escape key on the keyboard or pressing cancel.


// if the user exit the input field, and doesn't provide any value, it will return 'null', ie needs the second param which is optional
// let result = prompt("this is the title");
// console.log(result);


// cofirm: shows a question modal window ok and cancel as options, the result is true if OK, false if Cancel
// let accepted = confirm("are you happy?"); 

// type conversions: converting one value type to another type
// string conversion : converting from a value to string type

let trueval = true;
trueval = String(trueval);

console.log(trueval);

// numeric conversion: happens automatically in the cases of division, multiplication and modulo
console.log("3"/"4")

// we can alsoe explicitly convert it to Numeric value
let someVal = " 1 2 ";
console.log(Number(someVal)); // wrong it wll concatenate the strings and then convert to Num type

// undefined becomes NaN, null -> 0, true and false -> 1, 0, string whitespaces from front and end removed, if spaces in the middle it will give NaN

// bookean conversion -> if any value present or not empty it becomes true 1, whitespaces on strings count
// values like null, undefined, empty or empty strings, 0 it becomes false 0
console.log(Boolean(null));
console.log(Boolean(' ')); // true, because whitespace counts as well


// basic maths

// operand -> the value to which an operator is being applied
// an operator is unary if it has single operand like -a or -b
// an operator is binary if it has two operands like a-b
let a = 1, b = 2;
let sum = a + b;
let sub = a - b;
let mult = a * b;
let div = a / b;
let mod = a % b;
let expo = a ** b;

// for strings, + operator concatenates two or more strings, if any other operand in a mathematical expression is of any other value such as Numbers, it will be converted as a string.

// only binary addition '+' converts to the string type

console.log(5+5+'1'); // ex 1-> operators work from left to right so, it evals as 5+5 = 10, then 10+'1' = 101
// order will matter for ex
console.log('1'+5+5); // 155 

// but what if subtract?
console.log('1'+5-4); // first the mathematical expression is evaluated as 5-4 = 1 and then its appended to the string '1', type -> num

// other remaining math ops will convert the result into Number if string is included.


// Numeric conversion: Unary
// if there is a single operand +, it converts any value into Number type
console.log(typeof (+true));


// all operators in javascript returns some value, including '=' operator
let c = a + (b = a*a);
// c returns some value

// chain assignment is supported
a = b = c = 2+2; // all vals = 2+2
console.log(a,' ', b, ' ', c, ' ');


// increment and decrement only applies to some variables and not direct values like 5++, 3--

// comma op allows us to eval expressions, dividing with commma will store the latest or the last value in the expression
a = (3+3, 5+5);
console.log(a);


// comparison ops returns boolean result 
// equals == means equality test and assign = means assignment

// for string comparison, js uses lexicographical order, in simple words strings are compared letter by letter

// strings compard with nums becomes number

// strict equality checks the equality without type conversion, same goes for !== 
console.log(0==false); // type conversion occurs
console.log(0===false); // no type convesrion
console.log(0!=false);
console.log(0!==false);

// for math ops such as < > <= >= null become 0 and undefined becomes NaN
// funny and confusing
console.log(null>0);
console.log(null<0);
console.log(null>=0);
console.log(null<=0);
console.log(null==0); // false, because now null is not converted to 0 so we are just comparing 0 with null, null isnt a value


// conditonal operator ?*(ternary op)

let result = (age > 18)? true : false;
// the condition is evaulated, if its truthy then returns the first value or else second value, we can also use ternary operator multiple times. but generally it wil create readability issues.




// if(...) statement evaluates some condition if the result is true it evaluates the body
if(5 > 2){
   console.log('5 is greater than 2');
   // what if ther are 2 { }?
   {console.log('this is a nested {} block tho!');};
}

/*
   a number 0, empty string "", null, undefined, NaN all becomes false, these are called falsy values.
   all other values becomes truthy values.
*/
if(0 || undefined || null || NaN || "") {
   console.log('body entered');
}
else if(1){
   console.log('1 is truhty, body entered');
}

// basic test of if-else and prompt
let isCorrect = prompt('enter a value: ');
if(isCorrect == "ECMAScript") {
   alert('correct');
} else {
   alert('incorrect!');
}


// a !! is used for converting into boolean type
// loops are similiar to c++, var is not used because it leaks outside of the scope from the loop body, its better to use 'let'.

// switch statements also similar to c++
