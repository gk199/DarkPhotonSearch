from math import *
import sys
import argparse
import os
import time
import numpy as np
import copy
import textwrap
import fileinput
from datetime import date
import ROOT

from SetupLatex import *

print_latex = True

# ------------------------------------------------------------------------------
def main():
    file_path = sys.argv[1]
    #tree     = sys.argv[2]
    #weight   = sys.argv[3]	
	
    # Cutflow table for background and signal estimation: basic event selection
    print(" \n")
    print("Cutflow for analysis selections, done per event")
    print(" \n")
    event_selection_list = [
        "All events", 
        "Dimuon candidate", 
        "Drift chamber hits $< 10$", 
        "Dimuon $\\chi^2 \\geq 15$",
        "Dimuon pT $< 65$ GeV", 
        "Dimuon pT $< 50$ GeV", 
        "Hodoscope hits $< 18$"
    ]
	
    event_selection_list_abbrev = [
        "All       ", 
        "Dimuon cand",
        "Drift chamber hits",
        "Dimuon chi2",
        "Dimuon pT", 
        "Dimuon pT lower", 
        "Hodoscope hits",
    ]

    file = ROOT.TFile.Open(file_path)
    tree = file.Get("Events")

    selection_string = ""

    if print_latex:
        event_latex_setup(file_path)

    init = -1

    for i in range(len(event_selection_list)):
        selname = event_selection_list[i]
        selval  = -1
        Nevents = -1

        if i == 1: selection_string += "(n_dimuons > 0)"
        if i == 2: selection_string += "&& ((n_hits_d0x + n_hits_d2x + n_hits_d3mx + n_hits_d3px) < 10)"
        if i == 3: selection_string += "&& (dimuon_chisq[0] >= 15)"
        if i == 4: selection_string += "&& (dimuon_pmom_z[0] < 65)"
        if i == 5: selection_string += "&& (dimuon_pmom_z[0] < 50)"
        if i == 6: selection_string += "&& ((n_hits_h1x + n_hits_h2x + n_hits_h3x + n_hits_h4x) < 18)"

        selval = tree.GetEntries(selection_string)
        if i == 1: init = selval
        Nevents = tree.GetEntries()

        if print_latex:
            if (i == 0): print(selname+" &", round(selval, 4), "&", "", " \\\\ ")
            if (i > 0): print(selname+" &", round(selval, 4), "&", round(selval/init, 4), " \\\\ ")
            if (i == 1): print("\\hline")
            if (i == 6):
                latex_end(file_path)
        else:
            print(selection_list_abbrev[i], "\t", Nevents, "\t", round(selval, 4), "\t", round(selval/init, 4))

if __name__ == '__main__':
    main()