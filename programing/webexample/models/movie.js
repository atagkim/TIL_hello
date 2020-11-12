const mongoose = require('mongoose')
const mongooseAutoInc = require('mongoose-auto-increment');

const movieSchema = new mongoose.Schema({
    title: {
        type: String,
        required : true,
    }, 
    date: {
        type: Date,
        default: Date.now
    },
    imagePath: {
        type: String,
        required: true,
    }
})
movieSchema.plugin(mongooseAutoInc.plugin, 'movie');
module.exports = mongoose.model('movie', movieSchema)
