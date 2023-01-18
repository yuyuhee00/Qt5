function Component()
{
    // default constructor
}

Component.prototype.createOperations = function()
{
    component.createOperations();

    if (systemInfo.productType === "windows") {
        component.addOperation("CreateShortcut",
                               "@TargetDir@/analogclock",
                               "@StartMenuDir@/analogclock.lnk",
                               "workingDirectory=@TargetDir@",
                               "iconPath=@TargetDir@/main_icon.ico");
    }
}
