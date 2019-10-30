'use strict';

const mongoose = require("mongoose");
const app = require("./app");
// var bcrypt = require('bcrypt')

mongoose.Promise = global.Promise;

mongoose.connect('mongodb://localhost:27017/HackathonCR', {useNewUrlParser: true, useUnifiedTopology: true}).then(()=>{
    console.log("DB running successfully");

    app.set('port', process.env.PORT || 3000);
    app.listen(app.get('port'), ()=>{
        console.log(`Server running on port: '${app.get('port')}'`);
        // bcrypt.genSalt(2, (err, salt)=>{
        //     bcrypt.hash('admin123', salt, (err, hash) => {
        //         console.log(hash)
        //     })
        // })
    });
}).catch(err => console.log(err));
