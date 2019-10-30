'use strict';

var jwt = require("jwt-simple");
var moment = require("moment");
var secret = 'clave123';

exports.createToken = function(card){
    var payload = {
        sub: card._id,
        cardId: card.id,
        iat: moment().unix(),
        exp: moment().add(30, 'days').unix
    }

    return jwt.encode(payload, secret);
}