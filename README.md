# budgetsim
A school budget simulator!

This is school budget simulator! The goal of this game is to have as much money as possible at the end of a year.

School Budget Simulator is my first C++ project.

All characters and locations appearing in this work are fictitious. Any resemblance to real persons, living or dead, or locations, are purely coincidental.

## Contribute

### Prerequisites

- Install [Biicode](https://www.biicode.com/downloads)
- Install C++ tools: `$ bii setup:cpp`.
- Fetch dependencies: `$ bii init -L && bii find`

Refer to [Biicode guide](http://docs.biicode.com/c++/installation.html) in case of any problem.
If that doesn't help, search on StackOverflow or submit an issue on GitHub.

### Dev cycle

- [**Write tests**](https://en.wikipedia.org/wiki/Test-driven_development) for the changes you want to implement.  
See files in `tests/` for examples.
- **Check that the tests fail**:  
`$ bii build --target user_budgetsim_tests_main && bin/user_budgetsim_tests_main`
- **Write code**.  
In lieu of a formal styleguide, take care to maintain the existing coding style.
- **Check that the tests pass**:  
`$ bii build --target user_budgetsim_tests_main && bin/user_budgetsim_tests_main`
- **Run the app** when you're ready:  
`$ bii build --target user_budgetsim_src_main && bin/user_budgetsim_src_main`

### Submit a PR

Push to a separate branch in your fork (do not push to `master`), then create a Pull Request.
