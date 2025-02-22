/**
 * Implement a fucntion that to execute array of async tasks or promises in sequence. Collect both resolved values and rejected promises.
 */

//Function to creates an asynchronous task. Each task returns a promise which is resolved if a random number (from 0 to 9)
//is greater than 5, and rejected otherwise. The delay for each promise is proportional to the random number.
const createAsyncTask = () => {
  const randomValue = Math.floor(Math.random() * 10);
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      if (randomValue > 5) {
        resolve(randomValue);
      } else {
        reject(randomValue);
      }
    }, randomValue * 100);
  });
};
//Array of tasks containing multiple references to above asynchronous task function.
const tasks = [
  createAsyncTask,
  createAsyncTask,
  createAsyncTask,
  createAsyncTask,
  createAsyncTask,
];
//O(n) time complexity
const taskRunnerIterative = async (tasks, callback) => {
  const results = [];
  const errors = [];

  for (let task of tasks) {
    try {
      //wait for the promise to resolve
      const successfulTask = await task();
      results.push(successfulTask);
    } catch (failedTask) {
      errors.push(failedTask);
    }
  }
  callback(results, errors);
};
//O(n) time complexity
const taskRunnerRecursive = async (tasks, callback) => {
  const results = [];
  const errors = [];

  const runTask = (index = 0) => {
    if (index === tasks.length) {
      callback(results, errors);
      return;
    }
    tasks[index]()
      .then((successfulTask) => {
        results.push(successfulTask);
      })
      .catch((failedTask) => {
        errors.push(failedTask);
      })
      .finally(() => {
        runTask(index + 1);
      });
  };
  runTask();
};

taskRunnerIterative(tasks, (result, err) => {
  console.log(result, err);
});
taskRunnerRecursive(tasks, (result, err) => {
  console.log(result, err);
});

// Explanation:
// - createAsyncTask creates a promise based on a random value.
// - tasks array collects multiple instances of the asynchronous task.
// - taskRunnerIterative executes each task sequentially with await, gathering successes and errors in separate arrays.
// - taskRunnerRecursive uses recursion with promise chaining to achieve the same sequential execution.
// - Both functions call a callback with two arrays: one for resolved values and one for rejected values.
