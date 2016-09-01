/**
 * XadillaX created at 2016-09-01 15:44:45 With ♥
 *
 * Copyright (c) 2016 Souche.com, all rights
 * reserved.
 */
"use strict";

const fs = require("fs");
const path = require("path");

const Benchmark = require("benchmark");
const md5File = require("md5-file");

const md5 = require("../md5");

const filenames = [];

function loadFilename(directory) {
    //return filenames.push(path.resolve(__dirname, "../test/kisume.jpg"));
    const files = fs.readdirSync(directory);
    files.forEach(filename => {
        if(filename === ".git" || filename === "node_modules") return;
        const name = path.resolve(directory, filename);
        const stat = fs.statSync(name);
        if(stat.isFile()) {
            filenames.push(name);
        } else if(stat.isDirectory()) {
            loadFilename(name);
        }
    });
}

loadFilename(path.resolve(__dirname, ".."));

const suite = new Benchmark.Suite;

suite.add("md5-filex", function() {
    filenames.forEach(filename => md5.calculate(filename));
}).add("md5-file", function() {
    filenames.forEach(filename => md5File.sync(filename));
}).on("cycle", function(event) {
  console.log(String(event.target));
}).on("complete", function() {
  console.log("Fastest is " + this.filter("fastest").map("name"));
}).run();
