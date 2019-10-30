'use strict';

var express = require("express");
var CardController = require("../controllers/cardController");


var api = express.Router();
api.post('', CardController.register);
api.post('/login', CardController.login);
api.post('/actions', CardController.action);

module.exports = api;
