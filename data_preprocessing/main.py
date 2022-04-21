import pandas as pd
import numpy as np

df = pd.read_csv("data/data.tsv", sep='\t')
df2 = pd.read_csv("data/data2.tsv", sep='\t')
df.drop('POST_ID', axis=1, inplace=True)
df.drop('TIMESTAMP', axis=1, inplace=True)
df.drop('LINK_SENTIMENT', axis=1, inplace=True)
df.drop('PROPERTIES', axis=1, inplace=True)
df2.drop('POST_ID', axis=1, inplace=True)
df2.drop('TIMESTAMP', axis=1, inplace=True)
df2.drop('LINK_SENTIMENT', axis=1, inplace=True)
df2.drop('PROPERTIES', axis=1, inplace=True)

x = df['SOURCE_SUBREDDIT'].unique()
y = df['TARGET_SUBREDDIT'].unique()
new = np.unique(np.concatenate((x, y), 0))
x2 = df2['SOURCE_SUBREDDIT'].unique()
y2 = df2['TARGET_SUBREDDIT'].unique()
new2 = np.unique(np.concatenate((x2, y2), 0))
new3 = np.unique(np.concatenate((new, new2), 0))
# print(len(new))
# print(len(new2))
# print(len(new3))

df = df2.drop_duplicates()
df.to_csv('data/fixed_data.csv')