from flask import Flask,redirect,render_template,request
from cs50 import SQL
import os
import re
from flask_mail import Mail,Message

app=Flask(__name__)
app.config["MAIL_DEFAULT_SENDER"] = os.getenv("MAIL_DEFAULT_SENDER")
app.config["MAIL_PASSWORD"] = os.getenv("MAIL_PASSWORD")
app.config["MAIL_PORT"] = 587
app.config["MAIL_SERVER"] = "smtp.gmail.com"
app.config["MAIL_USE_TLS"] = True
app.config["MAIL_USERNAME"] = os.getenv("MAIL_USERNAME")
mail = Mail(app)

db=SQL("sqlite:///froshims.db")

# REGISTRANTS={}

SPORTS = [
    "Dodgeball",
    "Flag Football",
    "Soccer",
    "Volleyball",
    "Ultimate Frisbee"
]

@app.route("/")
def index():
    return render_template("index.html",sports=SPORTS)

@app.route("/register",methods=["POST"])
def register():
    name=request.form.get("name")
    if not name:
        return render_template("error.html",message="Missing name")
    email=request.form.get("email")
    if not email:
        return render_template("error.html",message="Missing email")
    sport=request.form.getlist("sport")
    if not sport:
        return render_template("error.html",message="Missing sport")
    if not all(s in SPORTS for s in sport):
        return render_template("error.html",message="Invalid sport")
    # REGISTRANTS[name]=sport

    for s in sport:
        db.execute("insert into registrants (name, sport) values(?,?)",name,s)
    
    message = Message("You are registered!", recipients=[email])
    mail.send(message)
    
    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    registrants=db.execute("select * from registrants")
    return render_template("registrants.html",registrants=registrants)      