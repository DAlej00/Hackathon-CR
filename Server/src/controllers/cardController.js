'use strict';

var Card = require("../models/card");
var Action = require('../models/action');
var bcrypt = require('bcrypt')

function register(req, res) {
    var params = req.body;

    if(params.id){
        var card = new Card();
        card.id = params.id;
        card.password = '$2b$04$UFxT.HAMccaemcOM70QmPeBX6I8aWtmW0mz5KpWU/CFBCXpWnP8Py';
        Card.findOne({id: card.id}, (err, found)=>{
            if(err) return res.status(500).send({message: 'Error en el servidor'});
            if(found) return res.status(404).send({message: 'Card already registered'})
            card.save((err, saved)=>{
                if(err) return res.status(500).send({message: 'Error en el servidor'});
                if(!saved) return res.status(404).send({message: 'Card already registered'})
                return res.status(200).send({card: saved})
            });
        })
    }else{
        res.status(200).send({message: 'All fields are required'});
    }
}

function login(req, res){
    var params = req.body;

    if(params.id && params.password){
        Card.findOne({id: params.id}, (err, found)=>{
            if(err) return res.status(500).send({message: 'Server error'});
            if(!found) return res.status(404).send({message: 'No card found'});
            bcrypt.compare(params.password, found.password, (err, check)=>{
                if(check){
                    found.password = null;
                    return res.status(200).send({card: found});
                }else return res.status(404).send({message: 'User no logged'});
            })

        })
    } else return res.status(404).send({message: 'All fields are required'})
}

function makeid(length) {
    var result = '';
    var characters = '@ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
    var charactersLength = characters.length;
    for (var i = 0; i < length; i++) {
        result += characters.charAt(Math.floor(Math.random() * charactersLength));
    }
    return result;
}

function action(req, res){
    var params = req.body;

    if(params.id && params.mode){
        Card.findOne({id: params.id}, (err, found)=>{
            if(err) return res.status(500).send({message: 'Error en el servidor'});
            if(!found) return res.status(404).send({message: 'Card no registered'});
            var action = new Action();
            action.cardId = params.id;
            action.mode = params.mode;
            action.place = 'Plaza Central';
            action.time = new Date();
            action.save((err, saved)=>{
                if(err) return res.status(500).send({message: 'Error en el servidor'});
                if(!saved) return res.status(404).send({message: 'Error saving the request'})
                return res.status(200).send({action: saved})
            })
        });
    }
}

module.exports = {
    register,
    login,
    action
}