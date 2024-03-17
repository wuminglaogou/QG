const express = require('express')
const joi = require('joi')
const app = express()
const cors = require('cors')
const config = require('./config')
const expressJWT = require('express-jwt')

app.use(cors())
app.use(express.json())
app.use(express.urlencoded({ extended: false }))

app.use((req, res, next) => {
    res.cc = function (err, status = 1) {
        res.send({
            status,
            message: err instanceof Error ? err.message : err
        })
    }
    next()
})

app.use(expressJWT({ secret: config.jwtSecretKey }).unless({ path: [/^\/api\//] }))
const router = require('./router/user')
app.use('/api', router)

app.use((err, req, res, next) => {
    if (err instanceof joi.ValidationError)
        return res.cc('账号或密码不符合要求!')
    if (err.name == 'UnauthorizedError')
        return res.cc('身份认证失败')
    res.cc(err)
})

app.listen(1080, () => {
    console.log('api server at http://127.0.0.1:1080')
})