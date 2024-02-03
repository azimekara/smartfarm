using Entities.Concrete;
using Microsoft.EntityFrameworkCore;
using Microsoft.IdentityModel.Protocols;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataAccess.Concrete.EntityFramework.Context
{
    public class EfContext : DbContext
    {
        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
             optionsBuilder.UseSqlServer("Server=MONSTER\\SQLEXPRESS03; Database=WebtekApi; integrated security=true; TrustServerCertificate=True;");
      
        }
        public DbSet<RainSensor> RainSensors { get; set; }
        public DbSet<RoofActivity> RoofActivities { get; set; }
        public DbSet<RoofActivityType> RoofActivityTypes { get; set; }
        public DbSet<MoveSensor> MoveSensors { get; set; }
        public DbSet<DoorActivity> DoorActivities { get; set; }
        public DbSet<FireSensor> FireSensors { get; set; }
        public DbSet<FireBuzzer> FireBuzzers { get; set; }
        public DbSet<FireFun> FireFans { get; set; }
        public DbSet<FoodSensor> FoodSensors { get; set; }
        public DbSet<FoodMachine> FoodMachines { get; set; }
        public DbSet<MoveBuzzer> MoveBuzzers { get; set; }

    }
}
