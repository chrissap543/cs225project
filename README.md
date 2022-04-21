# Building This Project

## Dataset Acquisition
We have provided access to the dataset we want to work on in `data/fixed_data.csv`. If you want to verify the creation of this data file, do the following:

Go to the linked Stanford Datasets called the [Reddit Hyperlink Network](http://snap.stanford.edu/data/soc-RedditHyperlinks.html) and select the file `soc-redditHyperlinks-body.tsv`, and move it to 
`./data/data.tsv`. Then, run 
```
python ./data_preprocessing/main.py
```
This will create/overwrite the `fixed_data.csv` in the `data` folder. Note that this python script depends on [`python`](https://www.python.org/downloads/), [`numpy`](https://numpy.org/install/), and [`pandas`](https://pandas.pydata.org/docs/getting_started/install.html). Guides to installing those dependencies are linked. 

## Running the project
First, run
```
mkdir bin
```
### Executable
To build the executable, run
```
make
```
To then run the executable, run
```
./bin/exec
```

### Test Suite
To build the test suite, run
```
make test
```
To run the test suite, run
```
./bin/test
```