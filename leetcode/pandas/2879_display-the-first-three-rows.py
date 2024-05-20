import pandas as pd

def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame:
    employees = employees[:3]
    return employees