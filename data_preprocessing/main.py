import pandas as pd

df = pd.read_csv("data/data.tsv", sep='\t')
df.drop('POST_ID', axis=1, inplace=True)
df.drop('TIMESTAMP', axis=1, inplace=True)
df.drop('LINK_SENTIMENT', axis=1, inplace=True)
df.drop('PROPERTIES', axis=1, inplace=True)
df = df.drop_duplicates()
df.to_csv('data/fixed_data.csv')