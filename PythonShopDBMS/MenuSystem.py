from DatabaseSetup import database
class menu():
    def __init__(self):
        self.db = database()
    def menuRunner(self):
        self.db.open_conn()
        print("Y")