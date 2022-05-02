import pandas as pd

lines = []
with open('../data/new_matrix_data.txt') as f:
  lines = f.readlines()

for i, x in enumerate(lines):
  lines[i] = x.strip()

df = pd.read_csv("../data/data.tsv", sep='\t')
df.drop('POST_ID', axis=1, inplace=True)
df.drop('TIMESTAMP', axis=1, inplace=True)
df.drop('LINK_SENTIMENT', axis=1, inplace=True)
df.drop('PROPERTIES', axis=1, inplace=True)

df.drop_duplicates(inplace=True)
df = df[df['SOURCE_SUBREDDIT'].isin(lines)]
df = df[df['TARGET_SUBREDDIT'].isin(lines)]

df.to_csv('../data/new_data.csv')