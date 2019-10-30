'use strict';

var mongoose = require("mongoose");
var Schema = mongoose.Schema;

var ActionSchema = Schema({
    cardId: String,
    mode: String,
    place: String,
    time: Date,
});

module.exports = mongoose.model('Actions', ActionSchema);
