import csv
import json
import traceback

from pyrx import Ap

print("added command jsontocsv")

path = "M:\\Dev\\Projects\\PyRxGit\\pyrx\\doc_utils\\resources\\docstrings.json"
patho = "M:\\Dev\\Projects\\PyRxGit\\pyrx\\doc_utils\\resources\\out.csv"


def foo(text: str):
    return "".join(i for i in text if ord(i) < 128)

@Ap.Command()
def jsontocsv() -> None:
    try:

        data = None
        newRows = []

        with open(path, "r") as file:
            data = json.load(file)
            id: int
            name: str
            desc: str
            for id, name, desc in data["rows"]:
                newRows.append({"ID": id, "NAME": name, "VALUE": foo(desc)})

        fieldnames = ["ID", "NAME", "VALUE"]
        with open(patho, "w", newline="") as csvfile:
            writer = csv.DictWriter(csvfile, fieldnames=fieldnames, delimiter="\t")
            writer.writeheader()
            writer.writerows(newRows)

    except Exception as err:
        traceback.print_exception(err)
