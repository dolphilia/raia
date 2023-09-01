// from https://v8.dev/features/modules

import {val} from './lib2.js';

print(val);

export const repeat = (string) => `${string} ${string}`;
export function shout(string) {
    return `${string.toUpperCase()}!`;
}