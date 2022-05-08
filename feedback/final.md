# Final Project Grade

Awesome work, everyone! I hope it was a rewarding experience for you all :D

Here are some parts of the final project grade (apart from contract, proposal, and midproject checkin).

If you would like to showcase your work, feel free to clone this repository and host it on your personal git account (github-dev.cs.illinois.edu is being retired soon).

## Development Log

### Grade 

Sophisticated (100%)

Development Log (5 pts)
- [x] >= 4 development logs

### Comments

______________________________________________________________

## Presentation
### Content Grade

Sophisticated (100%)

Final Presentation Content (10 pts)
- [x] A short summary of the goals set for the project and a statement of whether the goals were met.
- [x] Some highlights of the development process (dataset, major design choices, and testing)
- [x] Results of each method
- [x] Concluding thoughts (what was learned and what you would do next)

### Skills Grade

Sophisticated (100%)

Final Presentation Skills (5 pts)
- [x] Roughly equal responsibilities
- [x] Appropriate and understandable visual aids

### Comments

Great presentation overall. ~I'm just curious: what are some examples of a pair of subreddits that are in disconnected components?~ (nvm, you also provided a way to generate `nopath.txt`)


______________________________________________________________

## Written Report
### Grade

Sophisticated (100%)

Written Report (5 pts)
- [x] There are clear descriptions, figures, or tables of each method's output on the full target dataset.
- [x] Projects findings

### Comments

The report has every requirement. It would be interesting to read a deeper discussion on why (or your opinion) the observations make sense.

## README

### Grade

Sophisticated (100%)

Readme (5 pts)
- [x] The linkage and location of all major code, data, results, and deliverable files
- [x] The necessary commands to run the assignment, include instructions for selecting the input dataset and output location
- [x] Instructions on how to reproduce the tests

### Comments

Highly detailed instructions with clean formatting. CMake build works as intended (given reasonably up-to-date environment).

______________________________________________________________

## Code

### Goals Grade

Sophisticated (100%)

Code Goals (30 pts)
- [x] All methods listed in goals were successfully developed
- [x] All algorithms can be run on the full target dataset
- [x] All algorithms are thoroughly tested

### Execution Grade

Sophisticated (100%)

Code Execution (5 pts)
- [x] All methods and tests can be run
- [x] Ability to alter or adjust the input data and output location

### Efficiency Grade

Sophisticated (100%)

Code Efficiency (5 pts)
- [x] Code adheres to the expected Big O
- [x] There is no obvious inefficiency
- [x] Complete on target datasets

### Organization Grade

Competent (90%)

Code Organization (5 pts)
- [x] Code is human-readable
- [x] Unnecessary or obsolete code is completely absent

### Comments

The handcrafted argparse is neat and versatile! As a small improvement, it would be perfect to use long names for some arguments too (some `-<alphabet>` aren't intuitive to me).

Most algorithm implementation look good to me. DFS seems a bit foreign to me, specifically the bits on `graph.cpp:36-38` that restart a traversal on the unreachable node for some reason.

"**12828684** assertions in **34** test cases" says it all! The test covers a diverse set of cases. It also isolate tests for each component too.

Code organization is near production level. Among many details I likely miss, it features separation between `include` and `src`, well-structured directory hierarchy, comments with tags, and most importantly, clear and ergonomic interface/functionality boundaries between classes. Most `*.cpp` code chunks still lack comments to help future developers (such as your future self revisting) though.
