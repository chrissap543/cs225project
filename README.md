# Organization
The code is in the `include` and `source` directories. The tests are in the `tests` directory. The data is in the `data` directory and the data preprocessing scripts are in the `data_preprocessing` directory. The final deliverables are in in `documents/deliverables`. Note that the video presentation is stored on google drive and the link is in `video.md`. 

# Building This Project

## Dataset Acquisition
We have provided access to the dataset we want to work on in `data/fixed_data.csv`. If you want to verify the creation of this data file, do the following:

Go to the linked Stanford Datasets called the [Reddit Hyperlink Network](http://snap.stanford.edu/data/soc-RedditHyperlinks.html) and select the file `soc-redditHyperlinks-title.tsv`, and move it to 
`./data/data.tsv`. Then, run 
```
python ./data_preprocessing/main.py
```
This will create/overwrite the `fixed_data.csv` in the `data` folder. Note that this python script depends on [`python`](https://www.python.org/downloads/), [`numpy`](https://numpy.org/install/), and [`pandas`](https://pandas.pydata.org/docs/getting_started/install.html). Guides to installing those dependencies are linked. 

We also provide access to a largely reduced subset called `new_fixed_data.csv`. Note that we do not provide verification of creating this subset. We aimed to have the top 2000 subreddits by degree. However, we found that 3 of those had no edges to the other 1997, so we cut those as well. This is for Floyd-Warshall and betweeness centrality in order to keep memory usage and runtime to reasonable levels. 
## Running the project
First, run
```
mkdir build
```
Then
```
cmake ..
```
If your default CMake is below version 3.1, try
```
cmake3 ..
```
Then build both the executable and the test suite with
```
make
```
### Executable
To run the executable, run
```
./exec [flags]
```
By default, 
```
./exec
```
will not do anything. 
We specify a number of flags 
* -h: prints help info
* -t: runs depth first search
* -f: runs Floyd-Warshall algorithm
* -b: runs betweeness centrality
* -o: output to a file
* -r: read from a file

Here are some example usages:
```
./exec -h # prints help info
./exec -t -r data.csv # run depth first search on data.csv
./exec -f # check if path from all subreddits to all others
./exec -f <subreddit_1> <subreddit_2> # if path, prints the path between given subreddits
./exec -b 25 # runs betweeness centrality, prints top 25 central nodes
./exec -b -o out.txt # runs betweeness centrality, output to out.txt
```
Note that the subreddits that can be passed with 
```
./exec -f <subreddit_1> <subreddit_2>
```
must be of the top 1997 most subscribed subreddits. You can find a list of those at `data/new_matrix_data.txt`. 

### Test Suite
To build the test suite, run

To run the test suite, run
```
./test
```
Note that we provide a number of different tags for our test cases. 
```
./test [graph] # adjacency list graph
./test [data] # data processing
./test [processing] # helper method data processing
./test [traversal] # depth first search
./test [matrix] # adjacency matrix
./test [apsp] # Floyd-Warshall (all pair shortest path)
./test [between] # Betweeness Centrality
```