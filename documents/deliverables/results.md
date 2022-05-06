# Results

## Output of Algorithms
### Depth First Search
A full scale run of depth first search will print out the nodes in the order they were visited either to `std::out` or to a provided file. There are too many nodes to list here, but it will list each node on each individual line. 

### Floyd-Warshall
A full scale run of Floyd-Warshall will produce a matrix of distances and we also allow for backtracing of the path. However, since the dataset is large, we do not support printing or outputting the full matrix. Instead, we ask for two subreddits and we will print the path between those. Additionally, if no subreddits are given, then we check if there is a path between all subreddits in this subset of the data. 

### Betweeness Centrality
A full scale run of betweeness centrality will calculate the most central subreddits out of the top 2000 most subscribed subreddits. We are able to pass the number of central nodes we want to find and the code will find and print those nodes from most central to least central. 

## Correctness of Algorithms
For each algorithm, we wrote test cases to verify that they were working. We wrote these at every step. 
### Data Processing
The first step was to make sure the data processing was handled properly. We cannot verify that all of the dataset is in the produced data structure since there are too many nodes to check. However, we spot checked for data that we see in the data file and verified that it was part of the product. Furthermore, we tested the function on a small csv file and verified that the entire graph was what was expected. 

### Depth First Search
Depth first search was more difficult to test since we used an unordered map for storing our nodes. Using a map was not feasible due to the size of our dataset. Therefore, our test cases for depth first search are centered around making sure that every node was found, not that the depth first search produced the same ordering every time. For the small scale tests, we are able to check that all of the nodes are hit by simply iterating through them all. For the large scale dataset, we verify that chosen datapoints are hit at some point in the traversal. We do not verify that all datapoints are hit because there are simply too many datapoints to go through by hand. 

### Floyd-Warshall
We tested Floyd-Warshall in two ways. The first way was to verify that a small graph would have the exact distance matrix we expect. The other was to verify that the path construction indeed did have a valid path between nodes. We did this by checking that each step of the path were connected. 

### Betweeness Centrality


## Answer to Leading Question
### Is there a path between every subreddit?


### Most Central Subreddit
We found the most central subreddit to be `r/askreddit`. The next 4 were `subredditdrama`, `iama`, `outoftheloop`, and `dogecoin`.  