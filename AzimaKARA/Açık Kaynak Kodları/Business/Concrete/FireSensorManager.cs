using Business.Abstract;
using DataAccess.Abstract;
using Entities.Concrete;
using Entities.Dtos;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Business.Concrete
{
    public class FireSensorManager : IFireSensorService
    {
        private readonly IFireSensorDal _fireSensorDal;

        public FireSensorManager(IFireSensorDal fireSensorDal)
        {
            _fireSensorDal = fireSensorDal;
        }

        public void Add(FireSensorDto fireSensorDto)
        {
            FireSensor fireSensor = new FireSensor();
            fireSensor.isFire = fireSensorDto.isFire;
            fireSensor.date = DateTime.Now;

            _fireSensorDal.Insert(fireSensor);
        }

        public async Task<List<FireSensor>> GetAllData()
        {
            var data = await _fireSensorDal.GetList();
           return data.OrderByDescending(x => x.Id).ToList();
        }

        public async Task<FireSensor> GetEndData()
        {
            var data = await _fireSensorDal.GetList();
           return  data.OrderByDescending(x => x.Id).FirstOrDefault();
        }
    }
}
