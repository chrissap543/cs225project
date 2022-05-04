# Organization
The code is in the `include` and `source` directories. The tests are in the `tests` directory. The data is in the `data` directory and the data preprocessing scripts are in the `data_preprocessing` directory. The final deliverables are in in `documents/deliverables`. 

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
If your CMake is below version 3.1, try
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
./exec
```

### Test Suite
To build the test suite, run

To run the test suite, run
```
./test
```
Note that we provide a number of different tags for our test cases. 
For the adjacency list graph test cases, run
```
./test [graph] 
```
For the data processing test cases, run
```
./test [data]
```
For the only the helper method data processing test cases (not reading in files), run
```
./test [processing]
```
For the depth first search test cases, run
```
./test [traversal]
```
For the Floyd-Warshall test cases, run
```
...
```
For the betweeness centrality test cases, run
```
...
```