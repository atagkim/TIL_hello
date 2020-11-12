const Movie = require('../models/movie');
var express = require('express');
var router = express.Router();

router.post('/createmovie',function(req,res,next){

    const movie = new Movie({
        title : req.body.title,
        date : req.body.date,
        imagePath : req.body.imagePath
    });
    movie.save((err)=>{
        res.redirect('/');
    });

});

module.exports = router;
