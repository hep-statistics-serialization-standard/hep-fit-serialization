#include "RooRealVar.h"
#include "RooConstVar.h"
#include "RooGaussian.h"
#include "RooArgusBG.h"
#include "RooAddPdf.h"
#include "RooDataSet.h"
#include "RooPlot.h"

using namespace RooFit;

void runArgusModel() {
   // --- Observable ---
   RooRealVar mes("mes","m_{ES} (GeV)",5.20,5.30);

   // --- Parameters ---
   RooRealVar sigmean("sigmean","B^{#pm} mass",5.28,5.20,5.30);
   RooRealVar sigwidth("sigwidth","B^{#pm} width",0.0027,0.001,1.);

   // --- Build Gaussian PDF ---
   RooGaussian signalModel("signal","signal PDF",mes,sigmean,sigwidth);

   // --- Build Argus background PDF ---
   RooRealVar argpar("argpar","argus shape parameter",-20.0,-100.,-1.);
   RooArgusBG background("background","Argus PDF",mes,RooConst(5.291),argpar);

   // --- Construct signal+background PDF ---
   RooRealVar nsig("nsig","#signal events",200,0.,10000);
   RooRealVar nbkg("nbkg","#background events",800,0.,10000);
   RooAddPdf model("model","g+a",RooArgList(signalModel,background),RooArgList(nsig,nbkg));
   
   //We can now use this p.d.f. to generate an unbinned toy dataset, fit the p.d.f to that dataset using an unbinned maximum likelihood fit
   //and visualise the data with the p.d.f overlaid.

   // --- Generate a toyMC sample from composite PDF ---
   RooDataSet *data = model.generate(mes, 2000);

   RooJSONFactoryWSTool::loadExportKeys("wsexportkeys.json");
   RooWorkspace work;
   work.import(model);
   RooJSONFactoryWSTool tool(work);
   tool.exportJSON("argus.js");
}
