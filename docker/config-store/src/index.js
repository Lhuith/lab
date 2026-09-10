const express = require('express');
const cors = require('cors');
const bodyParser = require('body-parser');
const db = require('./db');
const apiRouter = require('./routes');

const port = process.env.PORT || 3000;
const app = express();

app.use(cors());
app.use(bodyParser.json());
app.use('/api', apiRouter);

app.get('/', (req, res) => {
	res.send('hello arda')
})

db.authenticate()
	.then(() => {
		console.log('connected to postgresql');
		return db.sync();
	})
	.then(() => {
		console.log('database synced, starting server');
		app.listen(port, () => {
			console.log(`server listing on port ${port}`)
		})
	})
	.catch(err => {
		console.error('unable to connect to db');
		console.error(err);
	});

