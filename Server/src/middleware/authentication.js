'use strict';

var jwd = require("jwt-simple");
var moment = require("moment");
var secret = 'clave123';

exports.ensureAuth = function(req, res, next){
    if(!req.headers.authorization){
        return res.status(404).send({message: 'Auth header missing'});
    }

    var token = req.headers.authorization.replace(/['"']+/g, '');
    
    try {
        var payload = jwd.decode(token, secret);
        if(payload.exp <= moment().unix()){
            return res.status(401).send({message: 'Expired token'});
        }
    } catch (error) {
        return res.status(404).send({message: 'No valid token'});
    }

    req.user = payload;

    next();

}
