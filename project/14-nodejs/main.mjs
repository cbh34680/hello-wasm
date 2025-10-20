import Module from './build/Debug/14_nodejs.js';

const emsModule = await Module({ arguments: ['nodejs'] });

let v = 0;
v = emsModule._increment(v);
console.log(`return=${v}`);
