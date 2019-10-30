'use strict'

const express = require("express");
const app = express();
const bodyparser = require("body-parser");

// //CARGAR RUTA
var cardRoutes = require("./routes/cardRoutes");

//MIDDLEWARES
app.use(bodyparser.urlencoded({ extended: false}));
app.use(bodyparser.json())

//CABECERAS
app.use((req, res, next) =>{
    res.header('Access-Control-Allow-Origin', '*');
    res.header('Access-Control-Allow-Headers', 'Authorization, X-API-KEY, Origin, X-Requested_With, Content-Type, Accept, Access-Control-Allow-Request-Method');
    res.header('Access-Control-Allow-Methods', 'GET, POST, OPTIONS, PUT, DELETE');
    res.header('Allow', 'GET, POST, OPTIONS, PUT, DELETE');

    next();
});

//RUTAS
app.use('/api/cards', cardRoutes);

//EXPORTAR LA/S VARIABLE/S QUE SE ESPECIFIQUEN
module.exports = app;

