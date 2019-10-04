#!/bin/sh
#this is program in "shell script"  Unix systems allow tremendous
#"programmability" using simple files containing commands just as
#you would execute them at the command line prompt.
#this one is running a command to generate readable, but unguessable
#system passwords.  It's fun to read the text it produces, sometimes
#it sounds alien:).
pwgen -0 -A -H /dev/null#elizabeth 
