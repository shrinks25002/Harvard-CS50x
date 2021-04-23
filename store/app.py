from cs50 import SQL
from flask import Flask, request, render_template, redirect, session
from flask_session import Session

app = Flask(__name__)

db = SQL("sqlite:///store.db")

app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/")
def index():
    books=db.execute("select * from books")
    return render_template("books.html",books=books)

@app.route("/cart",methods=["GET","POST"])
def cart():
    if "cart" not in session:
        session['cart']=[]
    if request.method=="POST":
        idee=request.form.get("id")
        if idee:
            session['cart'].append(idee)
        return redirect("/cart")
    books = db.execute("select * from books where id in (?)",session['cart'])
    return render_template("cart.html",books=books)
