'use strict';

var mongoose = require("mongoose");
var Schema = mongoose.Schema;

var CardSchema = Schema({
    id: String,
    password: String
});

module.exports = mongoose.model('Card', CardSchema);
