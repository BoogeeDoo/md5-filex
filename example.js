/**
 * XadillaX created at 2016-08-31 18:33:53 With ♥
 *
 * Copyright (c) 2016 Souche.com, all rights
 * reserved.
 */
"use strict";

const md5 = require("./md5");

md5.calculate("./test/leblanc.jpg", function(err, md5) {
    console.log("async1", err, md5);
});

md5.calculate("./test/leblanc.jpga", function(err, md5) {
    console.log("async1", err, md5);
});

console.log(md5.calculate("./test/leblanc.jpg"));

try {
    console.log(md5.calculate("./test/leblanc.jpga"));
} catch(e) {
    console.log(e);
}
