import pandas as pd
from io import StringIO

df = pd.read_csv(
    StringIO(
        """sky,windy,temp,humidity,enjoysport
sunny,no,warm,normal,yes
sunny,yes,low,high,no
sunny,yes,warm,low,yes
sunny,no,warm,normal,yes"""
    )
)

print(df)
df = df.query("enjoysport == 'yes'").iloc[:, :-1]
print("______________")
print(df)

print([df.iloc[0, i] if df.iloc[:, i].nunique() == 1 else "?" for i in range(df.shape[1])])
