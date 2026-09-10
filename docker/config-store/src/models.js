const { DataTypes } = require('sequelize')
const db = require('./db');
const sequilize = require('./db');

const KV = sequilize.define('KV', {
	key: {
		type: DataTypes.STRING,
		allowNull: false,
		unique: true
	},
	value: {
		type: DataTypes.STRING,
		allowNull: false,
	},
});

module.exports = { KV };
