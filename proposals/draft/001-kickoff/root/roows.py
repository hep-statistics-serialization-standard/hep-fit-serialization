import ROOT
import sys

ROOT.RooJSONFactoryWSTool.loadFactoryExpressions("wsfactoryexpressions.json")
ROOT.RooJSONFactoryWSTool.printFactoryExpressions()

ROOT.RooJSONFactoryWSTool.loadExportKeys("wsexportkeys.json")
ROOT.RooJSONFactoryWSTool.printExportKeys()

infile = sys.argv[1]

if infile.endswith(".yml"):
    ws = ROOT.RooWorkspace("ws1")
    tool = ROOT.RooJSONFactoryWSTool(ws)
    tool.importYML(infile)
    ws.writeToFile("ws.root")
elif infile.endswith(".js"):
    ws = ROOT.RooWorkspace("ws1")
    tool = ROOT.RooJSONFactoryWSTool(ws)
    tool.importYML(infile)
    ws.writeToFile("ws.root")    
elif infile.endswith(".root"):
    ifile = ROOT.TFile.Open(infile)
    for k in ifile.GetListOfKeys():
        if k.GetClassName() == "RooWorkspace":
            ws = k.ReadObj()
            break
    tool = ROOT.RooJSONFactoryWSTool(ws)
else:
    print("unknown file type "+infile)
    exit(0)
    
ws.Print("t")

print("exporting now")

tool.exportJSON("ws.js")

print("reimporting now")

ws2 = ROOT.RooWorkspace("ws2")
tool2 = ROOT.RooJSONFactoryWSTool(ws2)
tool2.importJSON("ws.js")
ws2.Print("t")

print("reexporting now")
tool2.exportYML("test.yml")
tool2.exportJSON("test.js")

