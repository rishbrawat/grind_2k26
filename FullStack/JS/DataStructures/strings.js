// strings in js are immutable, every operation returns a new string
let str = "hello ";
let len = str.length;
str = str.toUpperCase();
str = str.toLowerCase();

// trim()- removes spaces from start and end
str = str.trim();

// include(): checks if substring exists on the string
console.log(str.includes('he'));

let extractd = str.slice(1,4);
console.log(extractd);

str = "this is new updated string";
console.log(str);

// string now becomes an array
str = str.split(" ");
console.log(str);


str = str.join(extractd);
console.log(str);

let str2 = "this is not working";
console.log(str2.split("").reverse().join(""));
str2 = str2.replace("this", "that");
console.log(str2);


str2 = str2.replaceAll(" ", ",");
console.log(str2);

console.log(str2.indexOf("n"));
console.log(str2.lastIndexOf("n"));


