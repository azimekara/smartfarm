using Business.Abstract;
using Business.Concrete;
using DataAccess.Abstract;
using DataAccess.Concrete.EntityFramework;
using DataAccess.Concrete.EntityFramework.Context;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
builder.Services.AddDbContext<EfContext>();
builder.Services.AddScoped<IRainSensorDal, EfRainSensorDal>();
builder.Services.AddScoped<IRainSensorService, RainSensorManager>();

builder.Services.AddScoped<IRoofActivityDal, EfRoofActivityDal>();
builder.Services.AddScoped<IRoofActivityService, RoofActivityManager>();

builder.Services.AddScoped<IMoveSensorDal, EfMoveSensorDal>();
builder.Services.AddScoped<IMoveSensorService, MoveSensorManager>();

builder.Services.AddScoped<IMoveBuzzerDal, EfMoveBuzzerDal>();
builder.Services.AddScoped<IMoveBuzzerService, MoveBuzzerManager>();

builder.Services.AddScoped<IDoorActivityDal, EfDoorActivityDal>();
builder.Services.AddScoped<IDoorActivityService, DoorActivityManager>();

builder.Services.AddScoped<IFireSensorDal, EfFireSensorDal>();
builder.Services.AddScoped<IFireSensorService, FireSensorManager>();

builder.Services.AddScoped<IFireBuzzerDal, EfFireBuzzerDal>();
builder.Services.AddScoped<IFireBuzzerService, FireBuzzerManager>();

builder.Services.AddScoped<IFireFunDal, EfFireFunDal>();
builder.Services.AddScoped<IFireFunService, FireFunManager>();

builder.Services.AddScoped<IFoodSensorDal, EfFoodSensorDal>();
builder.Services.AddScoped<IFoodSensorService, FoodSensorManager>();

builder.Services.AddScoped<IFoodMachineDal, EfFoodMachineDal>();
builder.Services.AddScoped<IFoodMachineService, FoodMachineManager>();

builder.Services.AddCors(options =>
{
    options.AddDefaultPolicy(builder =>
    {
        builder.AllowAnyOrigin()
               .AllowAnyHeader()
               .AllowAnyMethod();
    });
});

builder.Services.AddControllers();
// Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}
app.UseCors();
app.UseHttpsRedirection();

app.UseAuthorization();

app.MapControllers();

app.Run();
