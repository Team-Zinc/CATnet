# Git Workflow
Please note that while not required, this will help you. When working on a new feature/fixing a bug on your fork, please create a new branch with a descriptive name. For example, if CATnet becomes sentient (lets say its issue #4387), we need to fix this bug. If you are tasked with this, you might:
```bash
git checkout main # Get back to main, if you are on another branch
git fetch origin # Get the latest code!
git reset --hard origin/master # Please note that this will delete all changes that you have made if you have not commit them
git checkout -b fix-sentience-#4387 # Create a new branch to fix the issue

# Make your changes

git add . # Add your files, generally always a good idea
git commit -m "Fixed issue #4387" # Please add a decent commit message
git push # Push your stuff to your fork!
git checkout main # Get back to the main branch
```
After this, you can then log into GitHub, navigate to your fork, select the branch you where working on, and file a pull request!
