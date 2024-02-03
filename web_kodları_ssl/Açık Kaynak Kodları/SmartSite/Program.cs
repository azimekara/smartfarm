
using Microsoft.AspNetCore.Components;
using Microsoft.AspNetCore.Components.Web;
using DataAccess.Concrete.EntityFramework.Context;
using DataAccess.Abstract;
using DataAccess.Concrete.EntityFramework;
using Business.Abstract;
using Business.Concrete;
using Blazored.Toast;
using Business.Hubs;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
builder.Services.AddDbContext<EfContext>();

builder.Services.AddScoped<IRainSensorDal, EfRainSensorDal>();
builder.Services.AddScoped<IRainSensorService, RainSensorManager>();

builder.Services.AddScoped<IChartService, ChartManager>();

builder.Services.AddScoped<IRoofActivityDal, EfRoofActivityDal>();
builder.Services.AddScoped<IRoofActivityService, RoofActivityManager>();

builder.Services.AddScoped<IRoofActivityTypeDal, EfRoofActivityTypeDal>();
builder.Services.AddScoped<IRoofActivityTypeService, RoofActivityTypeManager>();

builder.Services.AddScoped<IMoveSensorDal, EfMoveSensorDal>();
builder.Services.AddScoped<IMoveSensorService, MoveSensorManager>();

builder.Services.AddScoped<IDoorActivityDal, EfDoorActivityDal>();
builder.Services.AddScoped<IDoorActivityService, DoorActivityManager>();

builder.Services.AddScoped<IFireSensorDal, EfFireSensorDal>();
builder.Services.AddScoped<IFireSensorService, FireSensorManager>();

builder.Services.AddScoped<IFireBuzzerDal, EfFireBuzzerDal>();
builder.Services.AddScoped<IFireBuzzerService, FireBuzzerManager>();

builder.Services.AddScoped<IFireFunDal, EfFireFunDal>();
builder.Services.AddScoped<IFireFunService, FireFunManager>();

builder.Services.AddScoped<IMoveBuzzerDal, EfMoveBuzzerDal>();
builder.Services.AddScoped<IMoveBuzzerService, MoveBuzzerManager>();

builder.Services.AddScoped<IFoodSensorDal, EfFoodSensorDal>();
builder.Services.AddScoped<IFoodSensorService, FoodSensorManager>();

builder.Services.AddScoped<IFoodMachineDal, EfFoodMachineDal>();
builder.Services.AddScoped<IFoodMachineService, FoodMachineManager>();

builder.Services.AddBlazoredToast();
builder.Services.AddRazorPages();
builder.Services.AddServerSideBlazor();
builder.Services.AddDevExpressBlazor(options =>
{
    options.BootstrapVersion = DevExpress.Blazor.BootstrapVersion.v5;
    options.SizeMode = DevExpress.Blazor.SizeMode.Medium;
});

builder.WebHost.UseWebRoot("wwwroot");
builder.WebHost.UseStaticWebAssets();

var app = builder.Build();

// Configure the HTTP request pipeline.
if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Error");
    // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
    app.UseHsts();
}
app.UseHttpsRedirection();

app.UseStaticFiles();

app.UseRouting();


app.MapBlazorHub();
app.MapFallbackToPage("/_Host");
app.MapHub<RainHub>("/rainhub");
app.Run();