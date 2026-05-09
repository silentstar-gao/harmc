from flask import request
import Jinja2
@app.route("/profile/", methods=['GET'])
def profile():
    username = request.args.get('username')
    with open("profile.html") as f:
        content = f.read()
    return Jinja2.Template(content).render(username=username)