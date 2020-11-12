
const Movie = require('../models/movie');

var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {

  Movie.find({}).then((movies)=>{
    res.render('index', {movies:movies});
  }).catch((err)=>{
    console.log(err);
  });

  /*
  Movie.find({},'', (err, movies)=>{
    if(err) return console.error(err);
    res.render('list2', { title: 'Movies', movies : movies});
  })
*/
});

router.get('/insertmovie', function(req,res,next){
  res.render('newmovie',{ title: 'Express' });
});

router.get('/delete/:id', (req, res, next)=>{
  Movie.deleteOne({_id : req.params.id}).then((result)=>{
    res.redirect("/");
  });
});

router.get('/searchprestep', (req,res,next)=>{
  res.render("search");
});

router.post('/searchrequest', function(req, res, next){

  Movie.find(req.body,(err, movies)=>{
    res.render('index', {movies: movies});
  });
});

router.get('/edit/:id', (req, res, next)=>{

  Movie.findById(req.params.id ).then((movies)=>{
    res.render('edit', {movies : movies});
  }).catch((err)=>{
    console.log(err);
  });
});

router.post('/update/:id', (req,res,next)=>{
  Movie.findByIdAndUpdate(req.params.id, req.body, (err, movies)=>{
    res.redirect('/');
  });
});

module.exports = router;
