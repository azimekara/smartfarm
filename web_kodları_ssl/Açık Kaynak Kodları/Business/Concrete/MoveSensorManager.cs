using Business.Abstract;
using DataAccess.Abstract;
using DataAccess.Concrete.EntityFramework;
using Entities.Concrete;
using Entities.Dtos;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Business.Concrete
{
    public class MoveSensorManager : IMoveSensorService
    {
        private readonly IMoveSensorDal _moveSensorDal;

        public MoveSensorManager(IMoveSensorDal moveSensorDal)
        {
            _moveSensorDal = moveSensorDal;
        }

        public void Add(MoveSensorDto moveSensorDto)
        {
            MoveSensor moveSensor = new MoveSensor();
            moveSensor.AnimalNumber = moveSensorDto.AnimalNumber;
            moveSensor.Date = DateTime.Now;
            _moveSensorDal.Insert(moveSensor);
        }

        public async Task<MoveSensor> GetEndData()
        {
            var data = await GetMoveSensorAllData();
            return data.OrderByDescending(x => x.Id).FirstOrDefault();

        }

        public async Task<List<MoveSensor>> GetMoveSensorAllData()
        {
            return await _moveSensorDal.GetList();
        }
    }
}
