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
    public class MoveBuzzerManager : IMoveBuzzerService
    {
        private readonly IMoveBuzzerDal _moveBuzzerDal;

        public MoveBuzzerManager(IMoveBuzzerDal moveBuzzerDal)
        {
            _moveBuzzerDal = moveBuzzerDal;
        }

        public void Add(MoveBuzzerDto moveBuzzerDto)
        {
            MoveBuzzer moveBuzzer = new MoveBuzzer();
            moveBuzzer.BuzzerActivity = moveBuzzerDto.BuzzerActivity;
            moveBuzzer.Date = DateTime.Now;
            _moveBuzzerDal.Insert(moveBuzzer);
        }

        public async Task<MoveBuzzer> GetEndData()
        {
            var data = await _moveBuzzerDal.GetList();
            return data.OrderByDescending(x => x.Id).FirstOrDefault();
        }
    }
}
