# TheRQMProject


The project contains the complete set of attributes like OSEK, ACC ADXL345 drivers, to achieve the required functionality for Ride Quality Measurement.

Create workspace, repository, project from scratch
1) Create new workspace: File--> Switch worksapce --> Other . Type in or browse the directory name of the new workspace.
2) Create new git: File-->New-->Other-->Git-->Git Repository. Browse to the same directory as above workspace.
3) Create a new project: File --> New--> CCS project:
3.1) Select the target (I use Tiva TM4C123GH6PM)
3.2) Select the connection (I use Stellaris In-Circuit Debug Interface).
3.3) Select a project template and project name (default will be Empty Project with main.c) --> finish
4) Create and push to github: 
4.1) open github for windows --> click on "+" --> Add tab --> the directory path of the workspace above
4.2) Commit
4.3) Publish Repository: if you're already log-in before. Then just type name and description. Check private repository if you want to make it private ($7/per month).
5) Restart CCS