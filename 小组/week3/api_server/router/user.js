const express = require('express')
const router = express.Router()
const router_handler = require('../router_handler/user')
const expressJoi = require(`@escook/express-joi`)
const { reguser_schema } = require('../schema/user')
router.post('/reguser', expressJoi(reguser_schema), router_handler.reguser)


router.post('/login', expressJoi(reguser_schema), router_handler.login)
module.exports = router