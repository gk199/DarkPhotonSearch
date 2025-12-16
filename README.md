# Ntuple Plotter

Designed to plot the output of the SimHits MC files to identify helpful analysis variables. 

## Example 
```
mkdir Plots
root -b -q -l NtuplePlotterExample.C
```

The various plotting functions are defined in `NtuplePlotter.h`, which calls `PlotFunctions.h` for fits. `PlotParams.h` defines which TTree branches are used, and sets plot axis labels and ranges. In `RegionCuts.h`, TCuts are listed to be applied in the plotting script. `NtuplePlotterExample.C` shows how the plotting script is used, giving examples of overlaying histograms, fitting, applying selection cuts, ratio plotting, and making efficiency plots. 

Change the path of the input files (currently `string path = "../../DarkQuest/e1039-analysis/SimHits/macro/output_";` in `NtuplePlotterExample`). The naming convention is `output_*.root` where `*` is listed in the `filetags` list. 

Plotter adapted from Kiley Kennedy's [plotter](https://github.com/gk199/Run3-HCAL-LLP-Analysis/tree/main/MiniTuplePlotter). 

## Cutflow Tables
```
source /storage/utils/setup-e1039.sh 
python3 DarkPhoton_Cutflow.py <filepath to .root file>
python3 DarkPhoton_Cutflow.py ../../DarkQuest/e1039-analysis/SimHits/macro/output_background.root 
```
