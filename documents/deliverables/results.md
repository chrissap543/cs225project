# Results

## Output of Algorithms
### Depth First Search
A full scale run of depth first search will print out the nodes in the order they were visited either to `std::out` or to a provided file. There are too many nodes to list here, but it will list each node on each individual line. 

### Floyd-Warshall
A full scale run of Floyd-Warshall will produce a matrix of distances and we also allow for backtracing of the path. However, since the dataset is large, we do not support printing or outputting the full matrix. Instead, we ask for two subreddits and we will print the path between those. Additionally, if no subreddits are given, then we check if there is a path between all subreddits in this subset of the data. 

## Correctness of Algorithms
For each algorithm, we wrote test cases to verify that they were working. We wrote these at every step. 
### Data Processing
The first step was to make sure the data processing was handled properly. We cannot verify that all of the dataset is in the produced data structure since there are too many nodes to check. However, we spot checked for data that we see in the data file and verified that it was part of the product. Furthermore, we tested the function on a small csv file and verified that the entire graph was what was expected. 

### Depth First Search

### Floyd-Warshall

### Betweeness Centrality


## Answer to Leading Question
### Is there a path between every subreddit?


### Most Central Subreddit
We found the most central subreddit to be `r/place`.  You can find more information on `r/place` [here](https://en.wikipedia.org/wiki/R/place). This makes sense when contextualizing the subreddit. Every community would want to leave their mark on the canvas so thereby there would be links on their subreddit to enflame members to help their cause. Indeed, we note that offshoots of `r/place` take up 3 of the 5 top most central subreddits. 