# Proposal
## Leading Question
We want to look at the Reddit Hyperlink Network (which shows if there is a hyperlink between two subreddits) and see if you can get to any subreddit from any other subreddit (i.e. is Reddit 1 connected component). Furthermore, if two subreddits are connected, what is the shortest path between them. We also want to find the most central subreddit. 
## Dataset Acquisition and Processing
We are going to use a dataset from the Stanford Datasets called the [Reddit Hyperlink Network](http://snap.stanford.edu/data/soc-RedditHyperlinks.html). This dataset has 55,683 nodes and 858,490 edges. It comes as a TSV (Tab Separated Value) file with the headers: SOURCE_SUBREDDIT, TARGET_SUBREDDIT, POST_ID, TIMESTAMP, POST_LABEL, and POST_PROPERTIES. We will only be focusing on the SOURCE_SUBREDDIT and TARGET_SUBREDDIT columns. Each subreddit will be a node in the graph and each hyperlink from itself to another will be a directed edge. 

We will be checking for missing entries by ignoring them (i.e. if there is no listed link between subreddits, assume there is none). 

We are building an adjacency list of subreddits where adjacency is if there is a hyperlink from one subreddit to the other. We will build this list through a Node class which will contain the name of the subreddit it represents and a vector of pointers to other adjacent nodes. The estimated storage cost is O(n + m) where n is the number of nodes and m is the number of edges. 
## Graph Algorithms
We are going to use depth-first search for the traversal. For our other algorithms, we are using the Floyd-Warshall Algorithm and betweeness centrality. From the adjacency list described above, there is nothing more to be done for the two given algorithms. 

### Floyd-Warshall
The input of the Floyd-Warshall Algorithm is the graph itself. In another function, we will take two subreddits as inputs and find the shortest distance between them using the 2D array produced by the Floyd-Warshall Algorithm. We will then print that shortest distance to the console. This algorithm has a O(n<sup>3</sup>) and O(n<sup>2</sup>) space complexity. 

### Betweeness Centrality
We are going to use Brandes' Algorithm for this part. The input of Brandes' Algorithm is simply the graph itself and a positive integer. The output will be a list of that many central nodes in order of their centrality. We will aim for a time complexity of O(n*m) where n is the number of nodes and m is the number of edges and a space complexity of O(m+n).   

## Timeline
1. Data acquisition/processing (March 31st)
2. Depth-first earch (April 7th)
3. Floyd-Warshall (April 14th)
4. Betweeness Centrality (April 28th)
5. Video/report completed (May 5th)

If there is time after completing these deliverables, we will do a visualization of the dataset. 